<?php

/**
 * A handler for a voip menu item that returns say text if selected.
 */
class voipviews_handler_field_gosub extends views_handler_field {
  function query() {
  }

  function element_type() {
    return 'voipviews';
  }

  function option_definition() {
    $options['gosub_script'] = array('default' => '');
    $options['gosub_params'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['gosub_script'] = array(
      '#type' => 'select',
      '#title' => t('Script'),
      '#description' => t('VOIP script to use for this node.'),
      '#options' => VoipScript::getScriptNames(),
      '#default_value' => $this->options['gosub_script'],
    );
    // @todo what's the best way of getting people to enter the paramaters?
    $form['gosub_params'] = array(
      '#type' => 'textfield',
      '#title' => t('Parameters'),
      '#description' => t('Optional. Parameters to be sent to the script. Required as json - for now.'),
      '#default_value' => $this->options['gosub_params'],
    );
  }

  /**
   * If we can guarantee the voip context; then we could return array here?
   */
  function render($values) {
    return '';
  }

  function render_script($values) {
    $script = new voipScriptStore();
    if (! empty($this->options['gosub_script'])) {
      // token replacement; @todo should be made optional with ui and token list.
      $json = $this->options['gosub_params'];
      $tokens = $this->get_render_tokens($json);
      // we don't want to xss filter json so doing direct replacement
      $json = strtr($json, $tokens);
      $params = json_decode($json, true);
      $script->addGosub($this->options['gosub_script'], (array) $params);
    }
    return $script;
  }
}
