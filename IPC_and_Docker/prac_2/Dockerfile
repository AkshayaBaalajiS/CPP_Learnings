# 1. Step 1 base OS 
FROM ubuntu:22.04 as custom_builder

# 2. Dependencies (cmake dependency)
RUN  apt update && apt install python3 -y
RUN  apt update &&  apt install cmake -y

# 3. Source code 
#set working dir 
WORKDIR /home/akshayabaalaji-s/application
# copy the source_code folder from host to container  application folder  
COPY source_code/ source_code/

# 4. BUILD COMMANDS 
RUN mkdir /home/akshayabaalaji-s/application/build 
RUN cmake /home/akshayabaalaji-s/application/build/../source_code/

# 5. RUN the application 
CMD ./home/akshayabaalaji-s/application/build && cd /home/akshayabaalaji-s/application/build/array_sort.out 



