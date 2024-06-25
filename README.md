# Sandbox-3 for OpenGL

This is the boiler template for OpenGL. It contains the base needed for OpenGL to be up and running with few library packed, in <code>include</code> directory. 

<ul>
  <li>GLFW - OpenGL Context (for creating windows, handling inputs...)</li>
  <li>GLAD - OpenGL Loaders (to load openGL function pointers in ease)</li>
  <li>GLM - Math Library(includes vectors, matrix,...)</li>
  <li>Freetype - Text Loading Library (Glyph based)</li>
  <li>Stb - Image manipulation (reading, writing,...)</li>
</ul>

##### #Note : For fresh (Apple silicon) make sure to install few dependencies from homebrew
## 
    brew install gcc cmake freetype glfw
and also check if it is corretly installed in your system afterwards in terminal with commands
<ul>
<li><code>g++ --version</code></li>
<li><code>cmake --version</code></li>
</ul>

<h2>Follow as :</h2>
<ul>
  <li>Clone the project <code>git clone https://github.com/Thaparoshan143/OpenGL_Sandbox</code></li>
  <li>Switch to appropriate branch <code>git checkout pkg-3</code>
  <li>Change the code as per need with entry point at main.cpp (in sandbox)</li>
  <li><b>Cmake</b> is used as build system. Open the main directory (i.e. OpenGL_Sandbox)</li>
  <li>There are three shell script file (configure, build, run) for wrapping up cmake commands</li>
  <li>type command in terminal : <br/>
  <code>bash configure.sh - to generate make file from cmake</code><br/>
  <code>bash build.sh - run make file to create executable</code><br/>
  <code>bash run.sh - to run the application instance </code>
  </li>
</ul>

<b>If only basic boiler required, use other branch</b> : https://github.com/Thaparoshan143/OpenGL_Sandbox

#### Warning: This boiler is made using mac system (M1). Few things might need change on other patform in regard to how cmake is configured for linker and other stuffs
