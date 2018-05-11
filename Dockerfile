FROM base/archlinux
MAINTAINER mute1008 <mute1008@gmail.com>

RUN pacman -Syu && pacman -S --noconfirm nasm grub xorriso clang make mtools

WORKDIR /app
CMD ["make"]
