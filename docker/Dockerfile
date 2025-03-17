FROM ubuntu:20.04

# Set non-interactive mode to avoid timezone configuration prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install required packages for compiling C++ code and python interpreter
RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    make \
    cmake \
    git \
    wget \
    curl \
    python3 \
    python3-pip \
    python3-dev \
    && rm -rf /var/lib/apt/lists/*

RUN pip3 install --no-cache-dir matplotlib numpy

CMD ["/bin/bash"]