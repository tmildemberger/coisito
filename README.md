# Coisa para visualizar algoritmos de ordenação funcionando

## Instruções de compilação

  É necessário ter SFML instalado, assim como Ninja (https://github.com/ninja/ninja)
  e Meson. Se você tem python e o pip instalado, pode instalar o Meson com: (podem agradecer depois)
  ```bash
  pip install setup_tools meson
  ```
  
  Da primeira vez será necessário rodar
  ```bash
  meson build
  ninja -C build
  ```

  Mas para as eventuais próximas compilações será só
  ```bash
  ninja -C build
  ```

  Para executar o programito é necessário estar no diretório base do repositório e rodar
  ```bash
  ./build/coisito
  ```

  Se ocorrer algum problema estarei feliz em ajudar.
