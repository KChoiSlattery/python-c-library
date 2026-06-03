FROM debian:trixie-slim

WORKDIR /app

RUN apt update && apt install -y \
    git \
    build-essential


# RUN uv venv ../.venv --python 3.13
# RUN source ../.venv/bin/activate
# COPY requirements.in .
# RUN uv pip install -r requirements.in