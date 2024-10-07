#pragma once

const key_override_t comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SEMICOLON);
const key_override_t dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);
const key_override_t ques_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUES, KC_EXLM);
const key_override_t lprn_override = ko_make_basic(MOD_MASK_SHIFT, KC_LPRN, KC_LT);
const key_override_t rprn_override = ko_make_basic(MOD_MASK_SHIFT, KC_RPRN, KC_GT);

const key_override_t **key_overrides = (const key_override_t *[]){
    &comma_override,    // Shift+, returns ;
    &dot_override,      // Shift+. returns :
    &ques_override,     // Shift+? returns !
    &lprn_override,     // Shift+( returns <
    &rprn_override,     // Shift+) returns >
    NULL
};