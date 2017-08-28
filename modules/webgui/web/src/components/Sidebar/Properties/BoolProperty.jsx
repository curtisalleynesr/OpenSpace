import React from 'react';
import Property from './Property';
import Checkbox from '../../common/Input/Checkbox/Checkbox';

class BoolProperty extends Property {
  onChange(value) {
    // convert to Lua compatible value
    this.saveValue(value ? '1' : '0');

    // optimistic UI change!
    this.setState({ value });
  }

  render() {
    const { Description } = this.props;
    const { value } = this.state;
    return (
      <Checkbox
        checked={value === 'true'}
        label={(<span>{Description.Name} {this.descriptionPopup}</span>)}
        onChange={this.onChange}
        disabled={this.disabled}
      />
    );
  }
}

export default BoolProperty;
