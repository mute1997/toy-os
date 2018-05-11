FROM base/archlinux
MAINTAINER mute1008 <mute1008@gmail.com>

# RUN pacman -S --noconfirm build-essential nasm grub grub-pc-bin xorriso clang
RUN pacman -Syu && pacman -S --noconfirm nasm grub xorriso clang make

WORKDIR /app
CMD ["make"]
