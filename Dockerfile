FROM ubuntu
MAINTAINER mute1008 <mute1008@gmail.com>

RUN apt update && \
      apt install -y build-essential nasm grub grub-pc-bin xorriso clang

WORKDIR /app
CMD ["make"]
