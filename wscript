srcdir = '.'

blddir = 'build'

VERSION = '0.1.0'

def set_options(opt):
  opt.tool_options('compiler_cxx')

def configure(conf):
  conf.check_tool('compiler_cxx')
  conf.check_tool('node_addon')
  
  conf.check_cfg(package='bullet', args='--cflags --libs', mandatory=True)

def build(bld):
  bullet = bld.new_task_gen('cxx', 'shlib', 'node_addon')
  bullet.target = 'bullet'
  bullet.source = bld.glob('src/*.cc')
  bullet.uselib = ['BULLET']