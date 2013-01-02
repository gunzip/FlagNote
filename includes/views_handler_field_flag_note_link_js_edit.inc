<?php
/**
 * @file
 *
 * Field handler to present a link to modify a note.
 */
class views_handler_field_flag_note_link_js_edit extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['fnid'] = 'fnid';
    $this->additional_fields['uid'] = 'uid';
    $this->additional_fields['fid'] = 'fid';
  }
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }
  function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => 'Notes', 'translatable' => TRUE);
    return $options;
  }
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    ); 
  }
  function render($values) {
    $fnid = $values->{$this->aliases['fnid']};
    $uid  = $values->{$this->aliases['uid']};
    $fid = $values->{$this->aliases['fid']};
    $flag = flag_get_flag(NULL, $fid);
    if($flag->link_type != 'flag_note_form') {
      return;
    }
    drupal_add_js(drupal_get_path('module', 'flag_note') . '/flag_note_edit_form_wrapper.js', 'file');
    $text = '<div class = "flag_note_js_edit_form_button">' . check_plain($this->options['text']) . '</div>';
    $save_form = drupal_get_form('flag_note_js_edit_form_' .$fnid, $fnid);
    $text .= '<div class = "flag_note_js_edit_form " style="display:none">' . drupal_render($save_form) . '</div>';
    return $text;
  }
}
