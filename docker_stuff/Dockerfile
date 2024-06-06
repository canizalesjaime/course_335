FROM jaimec21/ubuntu:latest

SHELL [ "/bin/bash" , "-c" ]

# Windows line uncomment for non-windows
# RUN echo "LIBGL_ALWAYS_INDIRECT=0" >> ~/.bashrc
RUN apt update
# RUN apt-get install gcc
RUN apt install vim -y

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y git
# RUN apt install -y python3.9 python3.9-dev
# RUN sudo apt-get install net-tools

# RUN echo "all done"