truncate -s 0 templates.h
truncate -s 0 templates.c

function handle_file {
  t=$1
  l=$2
  path_name="${l%.mustache}"
  name="${path_name##*/}"
  name="${name^^}"
  #template=$(html-minifier --collapse-boolean-attributes --collapse-whitespace --minify-js true --minify-css true --quote-character \' $l | sed -e 's/\\/\\\\/g' | sed -e 's/"/\\"/g')
  template=$(sed -e 's/^[[:space:]]*//;s/[[:space:]]*$//' $l | tr -d '\n' | sed -e 's/\\/\\\\/g' | sed -e 's/"/\\"/g')
  echo "#define ${t}_${name} \"${template}\"" >> templates.h
  if [[ $path_name == partials/* ]]; then
    echo "\"${path_name}\", cJSON_String, ${t}_${name}," >> templates.c
  fi
}

function add_css {
  template=$(sed -e 's/^[[:space:]]*//;s/[[:space:]]*$//' static/css/lib/simplecss.min.css static/css/custom.css | tr -d '\n' | sed -e 's/\\/\\\\/g' | sed -e 's/"/\\"/g')
  echo "#define PART_CSS \"${template}\"" >> templates.h
  echo "\"partials/css\", cJSON_String, PART_CSS," >> templates.c
}

(
  echo "// This file is automatically generated. If any of the .mustache files is changed, rerun the generation."
  echo "#ifndef OIDC_PROMPT_TEMPLATES_H"
  echo "#define OIDC_PROMPT_TEMPLATES_H"
  echo
  echo '#include "wrapper/cjson.h"'
  echo
) >> templates.h

(
  echo "// This file is automatically generated. If any of the .mustache files is changed, rerun the generation."
  echo '#include "templates.h"'
  echo
  echo '#include <stddef.h>'
  echo
  echo '#include "utils/json.h"'
  echo
  echo 'const cJSON* _partials;'
  echo 'const cJSON* partials_json() {'
  echo 'if (_partials == NULL) {'
  echo '_partials = generateJSONObject('
) >> templates.c

LAYOUTS=$(ls layouts/*)
PARTIALS=$(ls partials/*)
SITES=$(ls sites/*)

for l in ${LAYOUTS[@]}; do
  handle_file "LAYOUT" $l
done
echo >> templates.h
for l in ${PARTIALS[@]}; do
  handle_file "PART" $l
done
add_css
echo >> templates.h
for l in ${SITES[@]}; do
  handle_file "SITE" $l
done


(
  echo 'NULL);'
  echo '}'
  echo 'return _partials;'
  echo '}'
  echo
) >> templates.c

(
  echo
  echo "const cJSON* partials_json();"
  echo
  echo "#endif // OIDC_PROMPT_TEMPLATES_H"
) >> templates.h
