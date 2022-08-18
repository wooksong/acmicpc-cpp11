input_file_template = 'input.txt.in'
if fs.exists(input_file_template)
  gen_input = custom_target('gen-input',
    output : ['input.txt'],
    input : ['input.txt.in'],
    command : [cp, '@INPUT@', '@OUTPUT@'],
    build_by_default : true,
  )
endif

num_problem = '6974'
src = [num_problem + '.cc']
executable(num_problem, src)
