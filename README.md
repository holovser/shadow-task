# Shadow Robot Task

## General explanation
This task was inially approached using normal Gaussian filtering technique. One of the challenges with that was adjusting standard deviation value and gaussian kernel (window size). Honestly speaking, the output seemed to be good enough after applying a gausian filter only without joining sections manually. These results can be found in intermediate_result folder (pure_gaussian_result) and the code is marked with v1.0.0 git tag so that this solution can be checked. The fourth attempt produced a smooth graph, however since it was requested to implement sections joining the final solution includes both manual sections detection, joining and applying the filter afterwards. The output of the final solution can be found under the file name: manual_joined_result.png.

The project implementation progress was commited to github so the approach can be inspected in a more detailed way.

## Visualization
A custom script was developed for visualising produced data and sample output. File: visualization/visualization.py

This script is also used in the docker environment in later sections of this readme.

## Project structure
The C++ solution is located in the solution_src folder. It's a simple CMake project with 2 unit tests. I was hoping I could implement more unit/integration tests, but I found myself way behind the schedule. Tests I implemented are located in tests/ folder and use google-test library.

This solution is supposed to be running on any OS, theoretically non-standard architectures such as ARM64 should be supported but that was never tested. It's assumed that a user would go through next section and launch a docker environment, however this project shouldn't be hard to build and run without docker. It should be taken into consideration that different files paths are absolute and are assume to be used as docker file system path, that could be the biggest issue when running this project without docker.

## Bulding and running instruction
It's assumed that docker is installed on the user OS. All the commands below are supposed to run in docker. 

```console
cd docker/
docker build -t cpp-compiler-image .
docker run -it -v <absolute_path_to_project>/shadow-task/:/shadow-task cpp-compiler-image /bin/bash
cd /shadow-task/solution_src
rm -rf build/
cmake -S . -B build
cmake --build build
cd build && ctest
./DataProcessing
```

The last command should produce a filtered_output.txt file in raw_data folder

```console
cd ../../visualization/
python3 visualization.py --path  /shadow-task/raw_data/filtered_output.txt
```

visualization.py script is supposed to produce a tmp_plot.png image in intermediate_result folder. This image can be viewed from a host system.



## Potential improvements
 - Avoid reading the whole file into vector, maybe read first 1000 values and do some sort of "window shifting" instead of stroing all 4k entries in vector.
 - Add more unit test, integration tests and end-to-end ones.
 - Make root Cmakelists file more modular