# Steps for Docker:
1. If image is not built , build it by running:
```
cd docker_stuff
docker build -t test_repo .
```      
2. Run from directory to mount: 
   ```
    docker run --name test_repo_container -it --rm -v ${PWD}/:/workspace test_repo
   ``` 


# Docker commands to remember:
1. docker ps -a (Shows container ids)
2. docker commit \<containerID\> \<repository\>:\<tag\> (to save changes on container to image)
3. docker rm \<containerID\> (delete container)
4. docker exec -it \<containerID\> bash (open another terminal in a current container)
5. docker tag NAME:tag myaccount/name:tag then docker push myaccount/name:tag


## Notes:
1. **You can also open in dev container to make above easier**. in vscode: reopen container at top prompt.
