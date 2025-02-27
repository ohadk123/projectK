FROM debian:latest

COPY build.sh /tmp/build.sh
RUN chmod +x /tmp/build.sh && /tmp/build.sh

ENV PATH="/root/opt/cross/bin:${PATH}"

WORKDIR /root/os

CMD [ "make" ]