FROM ubuntu:22.04

RUN apt update && apt install cmake -y && apt install -y cmake g++ make


WORKDIR /home/akshay

COPY . . 

RUN mkdir /home/akshay/build && cd /home/akshay/build && cmake .. && make 

# Each run are executed and the dir is returning to some other so for a single command it will work proper 
#RUN cmake /home/akshay
#RUN make  /home/akshay/build

CMD ["./build/app"]
