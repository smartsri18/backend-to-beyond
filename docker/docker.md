## Docker

Docker is a platform that helps you build, run, and manage applications using containers.

## Container

A container is like a lightweight, standalone box that packages your application code along with everything it needs to run: libraries, dependencies, environment variables, etc.

> Write once, run anywhere—without the 'it works on my machine' problem.

## Virtual Machine

A Virtual Machine (VM) is a software-based computer that runs on a physical machine (the host). It has its own operating system and works independently from other VMs. This lets you run different OSes (like macOS on a Windows PC) on the same hardware.

> VM runs Linux distribution as the guest OS on a host OS that is running a Windows.

## Docker vs VM's

| Feature        | Docker (Containerization)                   | Virtualization (VMs)                   |
| -------------- | ------------------------------------------- | -------------------------------------- |
| Technology     | Containers (share host OS kernel)           | Virtual Machines (full OS per VM)      |
| Performance    | Lightweight, fast startup                   | Heavier, slower startup                |
| Resource Usage | Minimal (no full OS)                        | High (each VM runs full OS)            |
| Isolation      | Process-level isolation                     | Hardware-level isolation               |
| Use Case       | Microservices, CI/CD, DevOps, scalable apps | Full OS simulation, legacy app support |

## Docker Core Components

| Component      | What it is                                                                |
| -------------- | ------------------------------------------------------------------------- |
| Container      | A running instance of the image.                                          |
| Image          | A snapshot (template) of your app with all dependencies.                  |
| Dockerfile     | A script that tells Docker how to build your app image.                   |
| Docker Hub     | Like GitHub, but for Docker images. You can push/pull images here.        |
| Docker CLI     | Command Line Interface to execute docker commands.                        |
| Docker Engine  | Core runtime to run containers.                                           |
| docker-compose | A tool to run multi-container applications easily (e.g., app + database). |

## Why Use Docker?

- Consistent environments across dev, test, and prod
- Lightweight and fast
- Easy to scale and manage
- Works across platforms (Linux, macOS, Windows)

## Docker Registry

A Docker Registry is a storage and distribution system for Docker images.

| Terms      | Usage                                                                                                |
| ---------- | ---------------------------------------------------------------------------------------------------- |
| Registry   | Stores a collection of docker images(dockerHub, AWS ECR, etc..). It can be public or private access. |
| Repository | Stores a collection of specific docker images with the same name but different versions.             |

> If Docker Hub is like GitHub (the platform), then a repository is like a GitHub repo.

## Dockerfile

A Dockerfile is a text file that contains step-by-step instructions to build a Docker image.

## Docker Network

Docker networks let containers talk to each other and to the outside world, with different modes for isolation and flexibility.

| Network Type     | Description                                | Use Case                        |
| ---------------- | ------------------------------------------ | ------------------------------- |
| bridge (default) | Creates a private network on your host     | For containers on the same host |
| host             | Shares the host’s network stack            | Faster but no isolation         |
| none             | No networking at all                       | Completely isolated container   |
| overlay          | Enables multi-host networking (Swarm mode) | Used in Docker Swarm clusters   |

## Docker compose

It is a tool that lets you define and run multi-container docker applications using a simple file(YAML). It manages multiple containers as one app (e.g., frontend + backend + database) also defines networks, volumes, dependencies, and environment variables.

## Docker Quick Notes

### Port Binding

- Always bind to `host:container`.
- Watch out for conflicts on host ports.

### depends_on in docker-compose

- Does not wait for service to be “ready,” only until the container is started.
- Use healthchecks for proper dependency control.

### Secrets & Configs

- export all environment variables to terminal.
- Or make consolidated environment variables in a file and use secret attribute.
