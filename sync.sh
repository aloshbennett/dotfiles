#!/usr/bin/bash

# Write usage comment
usage() {
    echo "Usage: sync.sh diff|pull|push"
}


if [ $# -lt 1 ]; then
    usage
    exit 0
fi

declare -a src=(
    "i3/i3blocks.conf"
    "i3/brightness.py"
    "i3/block"
    "i3/i3_multi_conf"
    "i3/mouse_toggle"
    "i3/cli_wrapper.sh"
    "i3/config"
    "sway/config"
    "tmux/.tmux.conf"
    "neovim/init.lua"
)

declare -a dst=(
    "$HOME/.config/i3/i3blocks.conf"
    "$HOME/.config/i3/scripts/brightness.py"
    "/dev/null/123"
    "$HOME/.config/i3/config"
    "$HOME/.config/i3/scripts/mouse_toggle"
    "$HOME/.config/i3/scripts/cli_wrapper.sh"
    "/dev/null/123"
    "$HOME/.config/sway/config"
    "$HOME/.tmux.conf"
    "$HOME/.config/nvim/init.lua"
)

declare -A files

fn_prepare() {
    len=${#src[@]}
    for (( i=0; i<$len; i++ )); do
        fs=${src[$i]}
        fd=${dst[$i]}
        if [ ! -f $fd ]; then
            continue;
        fi
        diff $fs $fd > /dev/null
        if (( $? )); then
            files["$fs"]=$fd
        fi
    done
}

fn_diff() {
    for src in "${!files[@]}"; do
        dst=${files[$src]}
        echo "$src -> $dst"
        read -p "Repo file '$src' different from '$dst'. See diff? [Y/n]" yn
        case $yn in
            [Nn]* )
                ;;
            * )
                diff --color=always $src $dst | less -r
                ;;
        esac
    done
}

fn_pull() {
    for src in "${!files[@]}"; do
        dst=${files[$src]}
        echo "$src -> $dst"
        read -p "Pull file '$src' from  repo and overwrite '$dst'? [Y/n]" yn
        case $yn in
            [Nn]* )
                ;;
            * )
                // cp $src $dst
                ;;
        esac
    done
}

fn_push() {
    for src in "${!files[@]}"; do
        dst=${files[$src]}
        echo "$src -> $dst"
        read -p "Push file '$dst' to repo? [Y/n]" yn
        case $yn in
            [Nn]* )
                ;;
            * )
                cp $dst $src
                ;;
        esac
    done
}

fn_prepare
case $1 in
    diff )
        fn_diff
        ;;
    pull )
        fn_pull
        ;;
    push )
        fn_push
        ;;
    * )
        usage
        ;;
esac

