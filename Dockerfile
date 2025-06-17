FROM ubuntu:latest AS build

WORKDIR /example

COPY client.c ./
COPY example_dev.c ./
COPY Makefile ./
COPY script_docker.sh ./
COPY init_ko.c ./

RUN chmod +x script_docker.sh

FROM ubuntu:latest

WORKDIR /opt/example

RUN apt-get update && apt-get -y install \
	dkms openssl xxd linux-headers-$(uname -r) \
	gcc make build-essential libncurses-dev bison flex libssl-dev libelf-dev dwarves kmod \
	linux-headers-`uname -r`

# Copy the binary from the build stage
COPY --from=build /example/script_docker.sh ./
COPY --from=build /example/Makefile ./
COPY --from=build /example/example_dev.c ./
COPY --from=build /example/client.c ./
COPY --from=build /example/init_ko.c ./

ENTRYPOINT [ "./script_docker.sh" ]
