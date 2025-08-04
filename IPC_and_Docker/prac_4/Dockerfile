FROM ubuntu:22.04

RUN apt update && apt install cmake -y && apt install -y g++ make

WORKDIR /home/akshay
COPY . .

RUN cd /home/akshay  && mkdir build && cd build && cmake .. && make 

CMD ["./build/problem_solution"]
