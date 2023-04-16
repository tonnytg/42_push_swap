FROM ubuntu:latest
WORKDIR /app
COPY . /app
RUN apt-get update && apt-get install -y gcc meson libcriterion-dev make
RUN make
CMD ["./push_swap"]