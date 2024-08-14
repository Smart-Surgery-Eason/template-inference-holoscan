ARG BASE_IMAGE=nvcr.io/nvidia/clara-holoscan/holoscan:v2.2.0-dgpu

# Set non-interactive installation environment
ARG DEBIAN_FRONTEND=noninteractive

# FROM ${BASE_IMAGE} AS builder
## Install necessary dependencies

# Production stage
FROM ${BASE_IMAGE}

# Set environment variables
ENV NVIDIA_DRIVER_CAPABILITIES=all
ENV HOLOSCAN_WORKDIR=/var/holoscan
ENV HOLOSCAN_INPUT_PATH=${HOLOSCAN_WORKDIR}/input
ENV HOLOSCAN_MODEL_PATH=${HOLOSCAN_WORKDIR}/models
ENV HOLOSCAN_OUTPUT_PATH=${HOLOSCAN_WORKDIR}/output

## Copy installed libraries and data from the builder stage
# COPY --from=builder /usr/local /usr/local
# COPY --from=builder /var/holoscan /var/holoscan

WORKDIR /app
COPY . .

# Remove the 'data' directory and set up necessary directories
RUN rm -rf data && \
    mkdir -p ${HOLOSCAN_WORKDIR} ${HOLOSCAN_INPUT_PATH} ${HOLOSCAN_OUTPUT_PATH} ${HOLOSCAN_MODEL_PATH} && \
    mkdir -p build && cd build && \
    cmake .. && \
    make -j$(nproc)

# Default command
CMD ["/bin/bash"]
