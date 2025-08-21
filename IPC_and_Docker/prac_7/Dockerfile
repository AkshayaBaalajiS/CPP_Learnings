FROM ubuntu:22.04

RUN apt update && apt install cmake -y g++ 

WORKDIR /home/akshay
COPY . . 

RUN mkdir /home/akshay/build && cd /home/akshay/build && cmake .. && make 

CMD ["./build/output"]