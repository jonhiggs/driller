function __run() {
  ${driller} $@ > ${stdout_file} 2> ${stderr_file}
  status=$?
  stdout=$(cat ${stdout_file})
  stderr=$(cat ${stderr_file})
}

function oneTimeTearDown() {
  rm -Rf /tmp/driller
  rm -Rf ${home_tmp}
  rm -f ${HOME}/.driller_tmpfile
}

function tearDown() {
  rm -Rf ${stdout_file} ${stderr_file}
}

function setUp() {
  cd ${running_dir}
}


# vim: ai ts=2 sw=2 et sts=2 ft=sh
