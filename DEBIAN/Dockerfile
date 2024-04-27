FROM ubuntu:22.04

LABEL vendor=ACME\ Incorporated \
      com.example.is-beta= \
      com.example.is-production="" \
      com.example.version="0.0.1-beta" \
      com.example.release-date="2015-02-12"


ENV TZ="Etc/UTC"

RUN apt-get update \
    && DEBIAN_FRONTEND=noninteractive apt-get install -yq \
        tzdata \
    && ln -fs /usr/share/zoneinfo/Etc/UTC /etc/localtime \
    && dpkg-reconfigure -f noninteractive tzdata

COPY abaddon /app/abaddon


#RUN DEBIAN_FRONTEND=noninteractive apt-get install -y g++
#RUN DEBIAN_FRONTEND=noninteractive apt-get install -y cmake
#RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libgtkmm-3.0-dev
#RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libcurl4-gnutls-dev
#RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libsqlite3-dev
#RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libssl-dev
#RUN DEBIAN_FRONTEND=noninteractive apt-get install -y nlohmann-json3-dev
#RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libhandy-1-dev
#RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libsecret-1-dev
#RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libopus-dev
#RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libsodium-dev
#RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libspdlog-dev


RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libgtkmm-3.0-1v5
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libcurl4-gnutls-dev
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libsqlite3-0
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libhandy-1-0
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libsecret-1-0
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libopus0
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libsodium23
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y libspdlog1


RUN /app/abaddon


#RUN apt-get update \
#    && apt-get install -yq tzdata \
#    && ln -fs /usr/share/zoneinfo/Etc/UTC /etc/localtime \
#    && dpkg-reconfigure -f noninteractive tzdata
#RUN apt-get install -y g++
#RUN apt-get install -y cmake
#RUN apt-get install -y libgtkmm-3.0-dev
#RUN apt-get install -y libcurl4-gnutls-dev
#RUN apt-get install -y libsqlite3-dev
#RUN apt-get install -y libssl-dev
#RUN apt-get install -y nlohmann-json3-dev
#RUN apt-get install -y libhandy-1-dev
#RUN apt-get install -y libsecret-1-dev
#RUN apt-get install -y libopus-dev
#RUN apt-get install -y libsodium-dev
#RUN apt-get install -y libspdlog-dev

#RUN apt-get update \
#    && DEBIAN_FRONTEND=noninteractive apt-get install -yq \
#        tzdata \
#    && ln -fs /usr/share/zoneinfo/Etc/UTC /etc/localtime \
#    && dpkg-reconfigure -f noninteractive tzdata \
#    && DEBIAN_FRONTEND=noninteractive apt-get install -yq \
#        g++ \
#        cmake \
#        libgtkmm-3.0-dev \
#        libcurl4-gnutls-dev \
#        libsqlite3-dev \
#        libssl-dev \
#        nlohmann-json3-dev \
#        libhandy-1-dev \
#        libsecret-1-dev \
#        libopus-dev \
#        libsodium-dev \
#        libspdlog-dev \
#    && rm -rf /var/lib/apt/lists/*
#
#
#COPY abaddon /app
#
#RUN ls /app && ls /app/build && mkdir -p /app/build
#
#RUN cd /app/build && cmake ..
#
#RUN cd /app/build && make


