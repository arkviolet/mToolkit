#!/usr/bin/env bash

sourcePath=$(cd $(dirname $0) && pwd)

cd $sourcePath/docker_platformer

# docker-compose -f cross.yaml run --rm dev

docker-compose -f cross.yaml run --rm dev  /bin/bash -c "echo alias sb=\'source /home/developer/workspace/enter_docker_dev.sh\' >> ~/.bashrc && /bin/bash"
