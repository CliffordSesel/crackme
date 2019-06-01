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

iwyu_tool = find_program(
  [
    'iwyu-tool',
    'iwyu_tool.py'
  ],
  required : false,
  native : true,
  disabler : true
)

iwyu_fix_includes = find_program(
  [
    'iwyu-fix-includes',
    'fix_includes.py'
  ],
  required : false,
  native : true,
  disabler : true
)

if iwyu_tool.found() and iwyu_fix_includes.found()
  iwyu = find_program(
    'iwyu-wrapper.sh', # The things Meson makes me do...
    required : true
  )
  run_target(
    'iwyu',
    command : [
      iwyu,
      iwyu_tool.path(),
      iwyu_fix_includes.path(),
      meson.build_root()
    ]
  )
endif
