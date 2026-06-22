FROM python:3.14-slim

WORKDIR /app

RUN apt update && apt install -y \
    git \
    build-essential