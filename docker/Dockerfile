FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y --no-install-recommends \
      binutils-mips-linux-gnu cpp-mips-linux-gnu make git python3 python3-pip \
      ca-certificates curl xz-utils ninja-build \
    && rm -rf /var/lib/apt/lists/*
RUN pip3 install --no-cache-dir "splat64[mips]" pyelftools colorama ansiwrap watchdog python-Levenshtein cxxfilt "m2c @ git+https://github.com/matt-kempster/m2c.git" "asm-differ @ git+https://github.com/simonlindholm/asm-differ.git" || \
    pip3 install --no-cache-dir "splat64[mips]" pyelftools
RUN git clone --depth 1 https://github.com/mkst/maspsx /opt/maspsx
# PsyQ-era GCC builds from decompals/old-gcc
RUN mkdir -p /opt/cc && cd /opt/cc && for v in 2.7.2-psx 2.8.1-psx 2.7.2-cdk 2.8.1 2.91.66; do \
      mkdir -p $v && (curl -fsSL https://github.com/decompals/old-gcc/releases/latest/download/gcc-$v.tar.gz | tar xz -C $v) || echo "missing $v"; done
# decomp-permuter: brute-forces near-miss C into a match
RUN git clone --depth 1 https://github.com/simonlindholm/decomp-permuter /opt/permuter \
    && pip3 install --no-cache-dir pycparser toml \
    && ln -s /usr/bin/mips-linux-gnu-cpp /usr/local/bin/cpp
WORKDIR /work
