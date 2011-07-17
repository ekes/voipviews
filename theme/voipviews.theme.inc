<?php

/**
 * @file
 *   Views theme related functions.
 */

/**
 * Preprocess voip output template.
 */
function template_preprocess_voipviews_views(&$vars) {
}

/**
 * As normal row handling, but it recieves a single field array rather than a row.
 */
function template_preprocess_voipviews_views_row(&$vars) {
  foreach ($vars['row'] as $id => $field) {
    // $field has really been created in the render() method.
    $vars['fields'][$id] = $field;
  }
}
