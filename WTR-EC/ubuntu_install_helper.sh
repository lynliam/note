#!/bin/bash

declare -A version_map
declare -A arch_map
version_map=([18.04]="bionic" [20.04]="focal" [22.04]="jammy" [22.10]="kinetic" [23.04]="lunar")
arch_map=([x86_64]="ubuntu" [aarch64]="ubuntu-ports")

echo "                         Ubuntu 一键重开脚本 v1.0                         "
echo "                                           By: Liam                     "
echo "                                           Update Time: 2023-12-30      "
echo " "
echo "脚本支持 Ubuntu 18.04、20.04、22.04、22.10、23.04 
架构支持 x86_64 aarch64(arm64)"
echo " "
echo " "
echo "----------------------------------start----------------------------------"

echo "正在换源..."
mkdir -p temp
file_path="./temp/sources.list"
destination_path="/etc/apt/sources.list"
if [ -e "$file_path" ]; then
    rm "$file_path"
fi

version_info=$(lsb_release -r)
system_arch=$(uname -m)
version_number=$(echo "$version_info" | awk '{print $2}')
version_code=${version_map[$version_number]}
#system_arch="aarch64"
echo "检测到:  Ubuntu version: $version_number ($version_code)"
echo "检测到:  System arch: $system_arch"
echo " "

default_version_code="jammy"
sources_content_tsinghua="# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-updates main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-backports main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-backports main restricted universe multiverse

deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-security main restricted universe multiverse
# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-security main restricted universe multiverse

# 预发布软件源，不建议启用
# deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-proposed main restricted universe multiverse
# # deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-proposed main restricted universe multiverse"

sources_content_hitsz="# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释
deb https://mirrors.osa.moe/ubuntu/ jammy main restricted universe multiverse
# deb-src https://mirrors.osa.moe/ubuntu/ jammy main restricted universe multiverse
deb https://mirrors.osa.moe/ubuntu/ jammy-updates main restricted universe multiverse
# deb-src https://mirrors.osa.moe/ubuntu/ jammy-updates main restricted universe multiverse
deb https://mirrors.osa.moe/ubuntu/ jammy-backports main restricted universe multiverse
# deb-src https://mirrors.osa.moe/ubuntu/ jammy-backports main restricted universe multiverse

deb https://mirrors.osa.moe/ubuntu/ jammy-security main restricted universe multiverse
# deb-src https://mirrors.osa.moe/ubuntu/ jammy-security main restricted universe multiverse

# deb http://security.ubuntu.com/ubuntu/ jammy-security main restricted universe multiverse
# # deb-src http://security.ubuntu.com/ubuntu/ jammy-security main restricted universe multiverse

# 预发布软件源，不建议启用
# deb https://mirrors.osa.moe/ubuntu/ jammy-proposed main restricted universe multiverse
# # deb-src https://mirrors.osa.moe/ubuntu/ jammy-proposed main restricted universe multiverse"

if [ "$system_arch" = "x86_64" ]; then
    echo "1. Option 清华源"
    echo "2. Option 哈工大深圳源（校内网下使用）"

    read -p "请选择源(填序号): " user_option
    case $user_option in
        1)
            echo "选择了 清华源"
            echo "$sources_content_tsinghua" > "$file_path"
            ;;
        2)
            echo "选择了 哈工大深圳源"
            echo "$sources_content_hitsz" > "$file_path"
            ;;
        *)
            echo "ERROR: 无效的选项！"
            echo "重来吧"
            exit 1
            ;;
    esac
else
    echo "$sources_content_tsinghua" > "$file_path"
fi

sed -i "s/"ubuntu"/${arch_map[$system_arch]}/g" "$file_path"
sed -i "s/$default_version_code/$version_code/g" "$file_path"

echo "原来存在的源备份为：/etc/apt/sources.list.backup"
sudo mv "$destination_path" "/etc/apt/sources.list.backup"
sudo cp "$file_path" "/etc/apt/"

if [ -e "$destination_path" ]; then
    echo "File exists at: $destination_path"
    echo "换源成功！"
else
    echo "File does not exist at: $destination_path"
    echo "遇到未知错误，换源失败！"
    exit 1
fi

echo "正在apt update..."
sudo apt update
sudo apt install wget python3-distro python3-yaml -y

echo " "
echo " "

echo "是否使用小鱼一键ROS下载脚本(Y/N):"
read -p "请输入: " user_option
case $user_option in
    Y|y)
        echo "选择了使用小鱼一键ROS下载脚本"
        mkdir -p /tmp/fishinstall/tools
        wget http://fishros.com/install/install1s/install.py -O /tmp/fishinstall/install.py 
        sudo python3 /tmp/fishinstall/install.py
        ;;
    N|n)
        echo "选择了不使用小鱼一键ROS下载脚本"
        echo " "
        ;;
    *)
        echo "选择了不使用小鱼一键ROS下载脚本"
        ;;
esac

echo "清理创建的文件..."
rm -rf temp
sudo python3 /tmp/fishinstall/install.py
sudo rm -rf /tmp/fishinstall/
echo "----------------------------------end----------------------------------"
