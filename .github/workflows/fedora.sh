#!/usr/bin/bash

set -eo pipefail

# Use grouped output messages
infobegin() {
	echo "::group::${1}"
}
infoend() {
	echo "::endgroup::"
}

# Required packages on Fedora
requires=(
	ccache # Use ccache to speed up build
)

# https://src.fedoraproject.org/cgit/rpms/caja-actions.git
requires+=(
	autoconf-archive
	caja-devel
	dblatex
	gcc
	git
	libxml2-devel
	libgtop2-devel
	libICE-devel
	libSM-devel
	libuuid-devel
	make
	mate-common
	gtk3-devel
	yelp-tools
)

infobegin "Update system"
dnf update -y
infoend

infobegin "Install dependency packages"
dnf install -y ${requires[@]}
infoend
