# S@OAO!-codebook

## Build Docker Image

```
docker-compose build
```

## Run the container first time

```
docker-compose up --remove-orphans -d
```

This command will create a container and run it at background

## Stop the container

First, use `docker ps` to see the name of the container.
Then run
```
docker stop $CONTAINER_NAME
```
Note that it just stop the container, which is not remove it.

## Rerun the container

```
docker start $CONTAINER_NAME
```

## Build PDF

Make sure that the container is running, then run
```
docker exec -it -w /data $CONTAINER_NAME /bin/bash
```
to get into the container. Then run
```
xelatex main.tex
```
to build.

## TODO LIST

- [x] Doing
- [ ] No one is doing
- [x] Treap
- [ ] Sparse Table
