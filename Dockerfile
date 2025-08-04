FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Bucharest

WORKDIR /app

RUN apt-get update && apt-get install -y \
git \
ruby-full \
build-essential \
cmake \
gcovr \
lcov \
&& apt-get clean && rm -rf /var/lib/apt/lists/*

RUN gem install ceedling

CMD ["/bin/sh", "-c", "mkdir build && cd build && cmake .. && make && cd .. && ceedling test:all && ceedling gcov:all"]