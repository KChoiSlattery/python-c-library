# python-c-library

Experimenting with ways to make a C backend for scientific computing in Python.

## Core tools used

- Linux test environment: Debian Docker container
- Language: C++
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
