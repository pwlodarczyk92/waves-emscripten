1. install emscripten sdk: https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html
2. create .env file: 
```
EMSDK_ENV=<emsdk_env.sh location>
PUBLIC_DIR=<static files directory>
```
3. build the project: `$ export $(cat .env | xargs) && ./build.sh`

