# 🚀 ProjectK

**ProjectK** is a minimalist hobby Operating System for educational purposes.  
It provides a bootloader and kernel built from scratch.

## 🔨 Building the Kernel

There are two ways to build the kernel:

### 1️⃣ Using a GCC Cross-Compiler

#### ✅ Requirements:
- ⚙️ [NASM](https://www.nasm.us/)
- 🛠️ [GCC Cross-Compiler](https://wiki.osdev.org/GCC_Cross-Compiler)
- 🖥️ [QEMU](https://www.qemu.org/)
- 📦 [Make](https://www.gnu.org/software/make/)

#### 📌 Steps:
1. Clone the repository:
   ```sh
   git clone https://github.com/ohadk123/projectK.git
   cd projectK
   ```
2. Run the build process:
   ```sh
   make
   ```

### 2️⃣ Using a Docker Image

A [Docker image](https://hub.docker.com/r/ohadk123/projectk-cc) containing the necessary cross-compiler is available.

#### ✅ Requirements:
- 🐳 [Docker](https://www.docker.com/)
- 🖥️ [QEMU](https://www.qemu.org/)

#### 📌 Steps:
1. Clone the repository:
   ```sh
   git clone https://github.com/ohadk123/projectK.git
   cd projectK
   ```
2. Run the Docker container:
   ```sh
   docker run -it --name projectk-cc -v .:/root/os ohadk123/projectk-cc
   ```
   This will pull the Docker image and build the kernel into `disk.img`.

## ▶️ Running the Kernel

Once you have `disk.img`, you can run the VM using QEMU:
```sh
make run
```
