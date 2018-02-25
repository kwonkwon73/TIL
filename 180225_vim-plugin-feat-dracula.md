## 문제
생코에서 본 dracula 프로젝트를 사용하는 에디터에 적용해보기

## 함께 본 자료
<https://draculatheme.com/vim/>

## 내용

생코에서 dracula라는 프로젝트를 보고 vim과 atom에 적용해봤다.

>https://www.facebook.com/permalink.php?story_fbid=1638726626215431&id=218158748272233
>
> 어떤 특정 에디터를 위한 테마가 아니라, 같은 컨셉의 디자인을 다양한 에디터에서 지원해주는 흥미로운 테마 프로젝트네요. 디자인도 꽤 준수합니다.

atom은 원래도 색상이 괜찮아서 크게 차이를 모르겠는데, vim은 확실히 보기가 좋아졌다.
(같은 컨셉의 디자인을 다양한 에디터에서 지원해주는...이라는 개념이 재밌다. UI 개인화 할 수 있는 여지를 찾고 있는데 좋은 예로도 살펴봐야겠다.)

또 이걸로 덕분에 vim에 플러그인 적용을 해볼 수 있었는데, 신기하다 ㅋㅋ 터미널 안에서 어떻게 이런게 다 되는지 모르겠다.
(GUI가 너무 익숙해서 콘솔로만 기능이 돌아가는게 낯설다.)

vim에 dracula 테마 플러그인 적용하기
1. Vim 플러그인 매니저 설치 ([vundle](https://github.com/VundleVim/Vundle.vim)을 사용했다.)
2. `~/.vimrc` 파일 수정, 터미널에 `vi ~/.vimrc`로 입력하면 된다.
3. Vundle의 Quick Start를 참고해 `Plugin 'dracula/vim'`를 입력한다. `daracula.vim` 파일을 `~/.vim/colors` 경로로 옮길 자신이 없으면 맨 아래 `syntax on`, `color dracula` 2줄을 더 입력한다.
  ```
  set nocompatible              " be iMproved, required
  filetype off                  " required

  " set the runtime path to include Vundle and initialize
  set rtp+=~/.vim/bundle/Vundle.vim
  call vundle#begin()
  " alternatively, pass a path where Vundle should install plugins
  "call vundle#begin('~/some/path/here')

  " let Vundle manage Vundle, required
  Plugin 'VundleVim/Vundle.vim'

  " The following are examples of different formats supported.
  " Keep Plugin commands between vundle#begin/end.
  " 여기서부터 예시로 적혀있는 플러그인 삭제하고 필요한 것만 입력하면 된다.
  Plugin 'dracula/vim'
  " https://draculatheme.com/vim/

  " All of your Plugins must be added before the following line
  call vundle#end()            " required
  filetype plugin indent on    " required
  " To ignore plugin indent changes, instead use:
  "filetype plugin on
  "
  " Brief help
  " :PluginList       - lists configured plugins
  " :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
  " :PluginSearch foo - searches for foo; append `!` to refresh local cache
  " :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
  "
  " see :h vundle for more details or wiki for FAQ
  " Put your non-Plugin stuff after this line

  syntax on
  color dracula
  ```
4. 적용 완료!
5. 필요에 따라 atom 등 추가로 사용하는 에디터에도 테마를 설치하면 된다.
