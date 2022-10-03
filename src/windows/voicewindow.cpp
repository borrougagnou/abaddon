#ifdef WITH_VOICE

// clang-format off

#include "voicewindow.hpp"
#include "components/lazyimage.hpp"
#include "abaddon.hpp"
// clang-format on

class VoiceWindowUserListEntry : public Gtk::ListBoxRow {
public:
    VoiceWindowUserListEntry(Snowflake id)
        : m_main(Gtk::ORIENTATION_HORIZONTAL)
        , m_avatar(32, 32)
        , m_mute("Mute") {
        m_name.set_halign(Gtk::ALIGN_START);
        m_name.set_hexpand(true);
        m_mute.set_halign(Gtk::ALIGN_END);

        m_main.add(m_avatar);
        m_main.add(m_name);
        m_main.add(m_mute);
        add(m_main);
        show_all_children();

        auto &discord = Abaddon::Get().GetDiscordClient();
        const auto user = discord.GetUser(id);
        if (user.has_value()) {
            m_name.set_text(user->Username);
        } else {
            m_name.set_text("Unknown user");
        }

        m_mute.signal_toggled().connect([this]() {
            m_signal_mute_cs.emit(m_mute.get_active());
        });
    }

private:
    Gtk::Box m_main;
    LazyImage m_avatar;
    Gtk::Label m_name;
    Gtk::CheckButton m_mute;

public:
    using type_signal_mute_cs = sigc::signal<void(bool)>;
    type_signal_mute_cs signal_mute_cs() {
        return m_signal_mute_cs;
    }

private:
    type_signal_mute_cs m_signal_mute_cs;
};

VoiceWindow::VoiceWindow(Snowflake channel_id)
    : m_main(Gtk::ORIENTATION_VERTICAL)
    , m_controls(Gtk::ORIENTATION_HORIZONTAL)
    , m_mute("Mute")
    , m_deafen("Deafen")
    , m_channel_id(channel_id) {
    get_style_context()->add_class("app-window");

    set_default_size(300, 300);

    auto &discord = Abaddon::Get().GetDiscordClient();
    SetUsers(discord.GetUsersInVoiceChannel(m_channel_id));

    m_mute.signal_toggled().connect(sigc::mem_fun(*this, &VoiceWindow::OnMuteChanged));
    m_deafen.signal_toggled().connect(sigc::mem_fun(*this, &VoiceWindow::OnDeafenChanged));

    m_controls.add(m_mute);
    m_controls.add(m_deafen);
    m_main.add(m_controls);
    m_main.add(m_user_list);
    add(m_main);
    show_all_children();
}

void VoiceWindow::SetUsers(const std::unordered_set<Snowflake> &user_ids) {
    for (auto id : user_ids) {
        auto *row = Gtk::make_managed<VoiceWindowUserListEntry>(id);
        row->signal_mute_cs().connect([this, id](bool is_muted) {
            m_signal_mute_user_cs.emit(id, is_muted);
        });
        m_user_list.add(*row);
    }
}

void VoiceWindow::OnMuteChanged() {
    m_signal_mute.emit(m_mute.get_active());
}

void VoiceWindow::OnDeafenChanged() {
    m_signal_deafen.emit(m_deafen.get_active());
}

VoiceWindow::type_signal_mute VoiceWindow::signal_mute() {
    return m_signal_mute;
}

VoiceWindow::type_signal_deafen VoiceWindow::signal_deafen() {
    return m_signal_deafen;
}

VoiceWindow::type_signal_mute_user_cs VoiceWindow::signal_mute_user_cs() {
    return m_signal_mute_user_cs;
}
#endif