function __run() {
  ${driller} $@ > ${stdout_file} 2> ${stderr_file}
  status=$?
  stdout=$(cat ${stdout_file})
  stderr=$(cat ${stderr_file})
}

function oneTimeSetUp() {
  test_dir=$(mktemp -d -t driller.XXX)
  realpath=$(which realpath || which grealpath)
  running_dir=$(${realpath} -- $(dirname $0))
  driller="${running_dir}/../driller"
  stdout_file="${test_dir}/stdout"
  stderr_file="${test_dir}/stderr"

  mkdir -p ${test_dir}/1 ${test_dir}/2 ${test_dir}/3
  touch "${test_dir}/1/file"
  touch "${test_dir}/1/a file with spaces"
  touch "${test_dir}/1/-file"
  touch "${test_dir}/1/--help"
  pushd "${test_dir}/2" &> /dev/null
  touch ${test_dir}/3/file
  ln -s /dev/null ${test_dir}/3/absolute_symlink
  ln -s ${test_dir}/3/absolute_symlink ${test_dir}/3/symlink_to_symlink
  ln -s ${test_dir}/3/linkloop2 ${test_dir}/3/linkloop1
  ln -s ${test_dir}/3/linkloop1 ${test_dir}/3/linkloop2

  pushd ${test_dir}/3 &> /dev/null
  ln -s ../1/ relative_symlink
  popd &> /dev/null

  ln -s ../1/file symlink
  ln ../1/file hardlink
  ln -s ../1/ symlink_to_dir
  popd &> /dev/null

  touch ${HOME}/.driller_tmpfile
  mkdir ${HOME}/.driller_tmpdir
  touch ${HOME}/.driller_tmpdir/file
}

function oneTimeTearDown() {
  rm -Rf ${test_dir}
  rm -Rf ${home_tmp}
  rm -f ${HOME}/.driller_tmpfile
  rm -Rf ${HOME}/.driller_tmpdir
}

function tearDown() {
  rm -Rf ${stdout_file} ${stderr_file}
}

function setUp() {
  cd ${running_dir}
}


# vim: ai ts=2 sw=2 et sts=2 ft=sh
