
libauth_sources = files(
  'crc.h',
  'crc.c',
  'metrics.h',
  'metrics.c',
  )

libcrc_inc = include_directories('.')

libcrc = static_library('CRC',
    sources : libcrc_sources,
    include_directories : libcrc_inc,
    dependencies : libcore_dep,
    install : false
)

libcrc_dep = declare_dependency(
    link_with : libcrc,
    include_directories : [libcrc_inc, srcinc],
)