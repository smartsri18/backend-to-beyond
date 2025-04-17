# docker commands

| Usage                                                 | Command                                                          |
| ----------------------------------------------------- | ---------------------------------------------------------------- |
| To list active running containers                     | `docker ps`                                                      |
| To list all used containers(both active and inactive) | `docker ps -a`                                                   |
| To list images or created containers in local         | `docker images`                                                  |
| To pull image from dockerhub                          | `docker pull ${imageName}:${tagVersion}`                         |
| To create and run service as container                | `docker run --name ${serviceName} -d ${imageName}:${tagVersion}` |
| To stop service                                       | `docker stop ${serviceName}`                                     |
| To start service                                      | `docker start ${serviceName}`                                    |
| To build a custom Dockerfile                          | `docker build -t ${imageName}:${tagVersion} /path-to-dockerfile` |
| To build a docker network                             | `docker network create ${networkName}`                           |
| To list all networks                                  | `docker network ls`                                              |
| To run the service in specific network                | `docker run -d --network ${networkName} ${imageName}`            |
| To login with dockerHub                               | `docker login`                                                   |
| To pull image from dockerhub registry to local        | `docker pull ${imageName}`                                       |
| To push local image to dockerhub registry             | `docker push ${imageName}`                                       |
| To read logs of specific container                    | `docker logs ${serviceName}`                                     |
| To remove container                                   | `docker rm ${serviceName}`                                       |
| To remove image                                       | `docker rmi ${imageName}`                                        |

# docker-compose commands

| Usage                                               | Command                                                            |
| --------------------------------------------------- | ------------------------------------------------------------------ |
| To create and run the multi-container in a network  | `docker-compose -f docker-compose.yml up`                          |
| To stop and remove the multi-container in a network | `docker-compose -f docker-compose.yml down`                        |
| To stop the multi-container in a network            | `docker-compose -f docker-compose.yml stop`                        |
| To start the multi-container in a network           | `docker-compose -f docker-compose.yml start`                       |
| To prefix with project name                         | `docker-compose --project-name webApp -f docker-compose.yml up -d` |
