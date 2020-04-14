FROM trafex/alpine-nginx-php7:latest
USER root
RUN apk add --no-cache bash 
RUN apk add --no-cache openssl
RUN apk add --no-cache vim 
RUN set -ex && apk --no-cache add sudo
COPY website/etc/nginx/nginx-tls.conf /etc/nginx/
RUN mkdir -p /etc/nginx/snippets/
#RUN cp /etc/nginx/
USER nobody
