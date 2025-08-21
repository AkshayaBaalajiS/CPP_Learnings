FROM ubuntu:22.04

RUN apt update && apt install g++ cmake -y 

WORKDIR /home/akshay
COPY . .

ENV REL_PATH=/home/akshay

RUN mkdir /home/akshay/build && cd /home/akshay/build && cmake .. && make 

CMD ["./build/server.exe"]