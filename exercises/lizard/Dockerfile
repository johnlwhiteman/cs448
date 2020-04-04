FROM python:alpine
RUN pip install lizard && \
    apk add --no-cache git openssh-client
RUN apk add bash && apk add --no-cache bash
RUN apk add cloc
RUN pip install jinja2
WORKDIR /lizard
RUN git clone https://github.com/johnlwhiteman/bad-human-code.git
