module use /opt/scorec/spack/rhel9/v0201_4/lmod/linux-rhel9-x86_64/Core/ \
module load gcc/12.3.0-iil3lno mpich/4.1.1-xpoyz4t \
module load simmetrix-simmodsuite/2023.1-230907dev-jquex4z \
module load cmake/3.26.3-2duxfcd \

cmake -S /path/to/this/folder -B build \
cd build \
make
