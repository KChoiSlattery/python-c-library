# python-c-library

Experimenting with ways to make a C backend for scientific computing in Python. Right now, using the ctypes example from [Writing a C/C++ extension for Python code](https://softwaremill.com/writing-a-c-c-extension-for-python-code/).

## Core tools used

- Build environment: Debian Docker container
- Language: C++
- Build system: Meson
- Python bindings: Pybind11
- Linear Algebra: Eigen

## Developer Instructions

Build the Docker image:

```sh
docker compose build
```

Start the Docker-compose service:

```sh
docker compose up -d
```

Connect to running service and use shell:

```sh
docker compose exec env bash
```

Connect to running service and use shell with virtual environment:

```sh
docker compose exec env sh -c "source ../.venv/bin/activate;sh"
```
