# FROM jaimec21/opencv-docker:latest

# RUN apt-get update && apt-get install -y

# # Install boost
# RUN apt-get install -y libboost-all-dev

# # Install Eigen
# RUN apt-get update && apt-get install -y libeigen3-dev

# RUN echo "LIBGL_ALWAYS_INDIRECT=0" >> ~/.bashrc


FROM ubuntu:latest

SHELL [ "/bin/bash" , "-c" ]

RUN apt update && \
    apt upgrade -y 

RUN apt install vim -y
RUN apt install build-essential -y
RUN apt install -y python3
RUN apt install python3-pip -y