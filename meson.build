project('ed', 'cpp', version: '0.1', default_options: ['warning_level=3'])

sfml_dep = dependency('sfml-all')
threads_dep = dependency('threads')

src = ['Sorters/SelectionSorter.cpp', 'Sorters/BubbleSorter.cpp', 'Sorters/Sorter.cpp', 'Button.cpp', 'Coisito.cpp', 'Thing.cpp', 'Managers/EventManager.cpp', 'Managers/GraphicsManager.cpp', 'VisibleState.cpp', 'main.cpp', 'State.cpp', 'StateManager.cpp', 'Menu.cpp', 'Container.cpp', 'VisibleThing.cpp', 'Desnome.cpp', 'VisibleContainer.cpp']

executable('coisito', src, dependencies: [sfml_dep, threads_dep])
