# Derived from https://hub.docker.com/r/owasp/dependency-check/dockerfile
FROM openjdk:8-jre-slim

ENV USER=dependencycheck
ENV VERSION=https://jeremylong.github.io/DependencyCheck/current.txt
ENV URL=https://dl.bintray.com/jeremy-long/owasp

RUN apt-get update                                 && \
    apt-get install unzip wget -y

RUN wget -O /tmp/current.txt ${VERSION}            && \
    version=$(cat /tmp/current.txt)                && \
    file="dependency-check-${version}-release.zip" && \
    wget "$URL/$file"                              && \
    unzip $file                                    && \
    rm $file                                       && \
    mv dependency-check /usr/share/
