;if (Drupal && Drupal.jsEnabled) {
  Drupal.behaviors.flag_note = function(context) {

    var $cbs = $('input[@name=link_type]');
    if (!$cbs.length) {
      return ;
    }
    var fid = 'edit-link-type-flag-note-form';
    var $fcb = $('#'+ fid);
    var $fopts = $('#flag-note-options');
    if (!$fcb.is(':checked')) {
      $fopts.hide();
    }
    $cbs.bind('click', function(e) {
      if ($(this).attr('id') == fid) {
        $fopts.slideDown();
      }
      else {
        $fopts.slideUp();
      }
    });

    $vocSelect = $('#edit-flag-note-flag-note-vocab');
    $vocOpts = $('#edit-flag-note-flag-note-vocab-label-wrapper, '+
                 '#edit-flag-note-flag-note-vocab-help-wrapper');

    if ($vocSelect.val() == 0) {
      $vocOpts.hide();
    }

    $('#edit-flag-note-flag-note-vocab').change(function(e){
      if ($(this).val() > 0) {
        $vocOpts.slideDown();
      }
      else {
        $vocOpts.slideUp();
      }
    });

  };
}
