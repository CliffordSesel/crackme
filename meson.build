#
# Copyright (c) 2019 Jasper Lowell
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, version 3.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#

project(
  'crackme',
  ['c'],
  default_options : [
    # Base options.
    'debug=false',
    'optimization=0',
    'warning_level=3',
    'werror=true',
    # Compiler options.
    'c_args=-fno-stack-protector'
  ],
  license : 'GPL3',
  meson_version : '>=0.50.1',
  version : '0.0.2'
)

libcurl = dependency('libcurl')

src_files = []
subdir('src')

subdir('scripts')
clang_tidy = find_program(
  'clang-tidy',
  required : false,
  native : true,
  disabler : true
)
if clang_tidy.found()
  run_target(
    'clang-tidy',
    command : [
      clang_tidy,
      '-checks=*',
      '-p', meson.build_root()
    ] + src_files,
  )
endif
