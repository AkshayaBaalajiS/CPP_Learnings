# Use an official GCC (C++ compiler) image
#FROM gcc:latest  large size 
FROM gcc:bullseye as builder

# Set the working directory in the container
WORKDIR /home/akshayabaalaji-s/cpp-practice


# Copy current directory contents into the container
COPY . .

#install the python 3 
RUN apt update && apt install python3 python3-pip -y 

# Cchecking the python version 
RUN python3 --version  > /home/akshayabaalaji-s/python_info 

# Compile the C++ program
RUN g++ -o sort_exe sort_array.cpp

# See the python version program
CMD cat /home/akshayabaalaji-s/python_info 

# Run the compiled binary
CMD ["./sort_exe"]
